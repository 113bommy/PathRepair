import sys

MOD = 1000000007

def solve(io):
  N = io.readInt()
  M = io.readInt()
  S = io.readIntArray(N)
  T = io.readIntArray(N)
  
  P = 0
  Q = 1
  A = 1
  B = 1
  for i in range(0, N):
    if S[i] == 0 or T[i] == 0:
      if S[i] == 0 and T[i] == 0:
        gtTop = M * (M - 1) * A
        gtBot = 2 * M * M * B
        eqTop = 1
        eqBot = M
      elif S[i] == 0:
        gtTop = (M - T[i]) * A
        gtBot = M * B
        eqTop = 1
        eqBot = M
      elif T[i] == 0:
        gtTop = (S[i] - 1) * A
        gtBot = M * B
        eqTop = 1
        eqBot = M
    elif S[i] > T[i]:
      gtTop = A
      gtBot = B
      eqTop = 0
      eqBot = 1
    elif S[i] < T[i]:
      gtTop = 0
      gtBot = 1
      eqTop = 0
      eqBot = 1
    elif S[i] == T[i]:
      gtTop = 0
      gtBot = 1
      eqTop = 1
      eqBot = 1
    P, Q = P * gtBot + gtTop * Q, Q * gtBot
    P %= MOD
    Q %= MOD
    A = (A * eqTop) % MOD
    B = (B * eqBot) % MOD
    if S[i] != 0 and T[i] != 0 and S[i] != T[i]:
      break
  io.println((P * modinv(Q, MOD)) % MOD)

def extended_gcd(aa, bb):
    lastremainder, remainder = abs(aa), abs(bb)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if aa < 0 else 1), lasty * (-1 if bb < 0 else 1)
 
def modinv(a, m):
	g, x, _ = extended_gcd(a, m)
	if g != 1:
		raise ValueError
	return x % m

# +---------------------+
# | TEMPLATE CODE BELOW |
# |    DO NOT MODIFY    |
# +---------------------+

# TODO: maybe reading byte-by-byte is faster than reading and parsing tokens.
class IO:
  input = None
  output = None
  raw = ""
  buf = []
  pos = 0
  
  def __init__(self, inputStream, outputStream):
    self.input = inputStream
    self.output = outputStream
  
  def readToBuffer(self):
    self.raw = self.input.readline().rstrip('\n')
    self.buf = self.raw.split()
    self.pos = 0
  
  def readString(self):
    while self.pos == len(self.buf):
      self.readToBuffer()
    ans = self.buf[self.pos]
    self.pos += 1
    return ans
  
  def readInt(self):
    return int(self.readString())
  
  def readFloat(self):
    return float(self.readString())
  
  def readStringArray(self, N, offset = 0):
    arr = [ None ] * offset
    for _ in range(0, N):
      arr.append(self.readString())
    return arr
  
  def readIntArray(self, N, offset = 0):
    arr = [ None ] * offset
    for _ in range(0, N):
      arr.append(self.readInt())
    return arr
  
  def readFloatArray(self, N, offset = 0):
    arr = [ None ] * offset
    for _ in range(0, N):
      arr.append(self.readFloat())
    return arr
  
  def readLine(self):
    while self.pos == len(self.buf):
      self.readToBuffer()
    if self.pos > 0:
      raise ValueError("Cannot call readline in the middle of a line.")
    return self.raw
  
  def print(self, s):
    self.output.write(str(s))
  
  def println(self, s):
    self.print(s)
    self.print('\n')
  
  def flushOutput(self):
    self.output.flush()

pythonIO = IO(sys.stdin, sys.stdout)
solve(pythonIO)
pythonIO.flushOutput()
