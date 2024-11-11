
n,k=map(int,input().split())
s=input()
k=k-1
s = s[:k]+str(s[k]).lower()+s[k+1:]
print(s)