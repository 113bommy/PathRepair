m,n=map(int,input().split())
z=input()
while(n):
    z=z.replace('BG','GB')
    n-=1
print(z)