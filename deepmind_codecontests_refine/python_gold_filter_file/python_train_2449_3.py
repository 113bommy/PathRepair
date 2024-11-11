a,b=list(map(int,input().split()))
c,d=list(map(int,input().split()))
print('YES' if (b-c<=1 and (c-2)/b<=2) or (a-d<=1 and (d-2)/a<=2) else 'NO')