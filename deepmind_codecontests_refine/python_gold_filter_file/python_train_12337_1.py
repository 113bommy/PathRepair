n,m = map(int, input().split())
ch = str(input())
res = [ch[k] for k in range(n)]
X = ["" for _ in range(m)]
Y = ["" for _ in range(m)]
for k in range(m):
    s = str(input()) 
    X[k] = s[0]
    Y[k] = s[2]

al = "abcdefghijklmnopqrstuvwxyz"
A = [al[k] for k in range(26)]
B = A[:]
for k in range(m):
    a = A.index(X[k])
    b = A.index(Y[k])
    c = A[a]
    A[a] = A[b]
    A[b] = c            
for j in range(n):
    a = B.index(res[j])
    res[j] = A[a]
    
ch = ""
for k in range(n):
    ch  = ch + res[k]
print(ch)
