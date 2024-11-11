n = int(input())
A = []
for i in range(n):
  x = list(map(int,input().split()))
  A.append(x)
if n == 1:
  print(1)
else:
  row = -1
  col = -1
  for i in range(n):
    for j in range(n):
      if A[i][j] == 0:
        row = i
        col = j
  s = 0
  val = 0
  if row <n-1:
    s = sum(A[row+1])
    z = sum(A[row])
    val = s-z
    A[row][col] = val
  else:
    s = sum(A[row-1])
    
    z = sum(A[row])
    
    val = s - z
    A[row][col] = val
  

def isMagicSquare(mat) : 
      
    # calculate the sum of  
    # the prime diagonal 
    s = 0 
    N = len(mat) 
    for i in range(0,N) : 
        s = s + mat[i][i] 
  
    # the secondary diagonal 
    s2 = 0
    for i in range(0,N ) : 
        s2 = s2 + mat[i][N-i-1] 
  
    if(s!=s2) : 
        return False
  
    # For sums of Rows  
    for i in range(0, N) : 
        rowSum = 0;      
        for j in range(0, N) : 
            rowSum += mat[i][j] 
          
        # check if every row sum is 
        # equal to prime diagonal sum 
        if (rowSum != s) : 
            return False
  
    # For sums of Columns 
    for i in range(0, N): 
        colSum = 0
        for j in range(0, N) : 
            colSum += mat[j][i] 
  
        # check if every column sum is  
        # equal to prime diagonal sum 
        if (s != colSum) : 
            return False
  
    return True
if n!=1:
  if isMagicSquare(A) == True and val>=1:
    print(val)
  else:
    print(-1)
