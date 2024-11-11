n,m,a,b=map(int,input().split())
if n>=m:
    print(min((b*(n//m)+(n%m)*a),a*n,(b*(n//m)+b)))
else:
    print(min(b,n*a))