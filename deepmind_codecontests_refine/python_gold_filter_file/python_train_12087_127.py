n=int(input())
ans=input().split()
k=0
while k<n and ans[k]=="0":
    k=k+1
if k<n:
    print("HARD")
else:
    print("EASY")