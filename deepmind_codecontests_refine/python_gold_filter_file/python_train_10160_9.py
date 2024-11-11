import math 
#------------------------------warmup----------------------------
import os
import sys
from io import BytesIO, IOBase
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
#-------------------game starts now----------------------------------------------------
def binarySearchCount(arr, n, key): 
  
    left = 0
    right = n 
   
    mid = 0
    while (left < right): 
      
        mid = (right + left)//2
   
        # Check if key is present in array 
        if (arr[mid] == key): 
          
            # If duplicates are 
            # present it returns 
            # the position of last element 
            while (mid + 1<n and arr[mid + 1] == key): 
                 mid+= 1
            break
          
   
        # If key is smaller, 
        # ignore right half 
        elif (arr[mid] > key): 
            right = mid 
   
        # If key is greater, 
        # ignore left half 
        else: 
            left = mid + 1
      
   
    # If key is not found in 
    # array then it will be 
    # before mid 
    while (mid > -1 and  arr[mid] > key): 
        mid-= 1
   
    # Return mid + 1 because 
    # of 0-based indexing 
    # of array 
    return mid + 1
n,m,k,t=map(int,input().split())
s=set()
w=["Carrots","Kiwis","Grapes"]
d=dict()
for i in range(k):
    a,b=map(int,input().split())
    s.add((a,b))
    if a in d:
        d[a].append(b)
    else:
        d.update({a:[b]})
for i in d:
    d[i].sort()
pre=[0]*(n+1)
for j in range(n):
    if j+1 in d:
        pre[j+1]=pre[j]+len(d[j+1])
    else:
        pre[j+1]=pre[j]
for i in range(t):
    a,b=map(int,input().split())
    if (a,b) in s:
        print("Waste")
        continue 
    ori=(a-1)*m+b-1
    se=pre[a-1]
    if a in d:
        se+=binarySearchCount(d[a], len(d[a]), b)
    #print(se)
    print(w[(ori-se)%3])