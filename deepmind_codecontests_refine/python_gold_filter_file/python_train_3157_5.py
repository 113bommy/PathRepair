def readArr():
  return [int(x) for x in input().split()]

def isPalindrome(s):
  n = len(s)
  for i in range(n//2):
    if s[i] != s[n-i-1]:
      return False
  return True

def solveB(N, s):
  zr = s.count('0')
  if zr%2 == 0:
    print("BOB")
    return
  else:
    if zr == 1:
      print("BOB")
      return
    else:
      print("ALICE")
      return

def solve():
  N = int(input())
  s = input()

  if isPalindrome(s):
    solveB(N,s)
  else:
    K = None
    for i in range(N):
      if s[i] == '1': continue
      k = s[:i]+"1"+s[i+1:]
      if isPalindrome(k): K = k
    if K:
      if K.count('0') == 1:
        print("DRAW")
        return
      else:
        print("ALICE")
        return
    else:
      print("ALICE")


if __name__ == "__main__":
  # T = 1
  T = int(input())
  for t in range(T):
    solve()
