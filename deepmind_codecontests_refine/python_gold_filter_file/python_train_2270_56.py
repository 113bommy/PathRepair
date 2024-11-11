n,k=map(int,input().split())
s=str(input())
print(s[0:k-1]+str.lower(s[k-1])+s[k:])