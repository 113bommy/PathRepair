S=input()
w=int(input())
n=len(S)
T=""
for i in range (0,n,w):
  T+=S[i]
print(T)