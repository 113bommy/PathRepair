A=[list(map(int,input().split())) for _ in range(3)]
N=int(input())
bn=[int(input()) for _ in range(N)]
ans=False
for ver in zip(*A):
    if all(item in bn for item in ver):
        ans=True
for wide in A:
    if all(item in bn for item in wide):
        ans=True
if all(A[i][i] in bn for i in range(3)):
    ans=True
if all(A[i][3-i-1] in bn for i in range(3)):
    ans=True
if ans==True:
    print("Yes")
else:
    print("No")