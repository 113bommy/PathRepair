a,b=map(int,input().split())
def get(a):
    return list([i,j] for i in range(1,a) for j in range(1,a) if i*i+j*j==a*a)
A=get(a)
B=get(b)
for [a,b] in A:
    for [c,d] in B:
        if a*c==b*d and b!=d:
            print("YES\n0 0\n%d %d\n%d %d" %(-a,b,c,d))
            exit(0)
print("NO")