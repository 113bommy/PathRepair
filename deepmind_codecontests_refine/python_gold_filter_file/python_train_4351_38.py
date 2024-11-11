a,b,c = [int(x) for x in input().split()]
d,e,f = [int(x) for x in input().split()]
g,h,i = [int(x) for x in input().split()]

n = int(input())
S = {int(input()) for x in range(n)}

def q(x,y,z):
    return x in S and y in S and z in S

print('Yes' if q(a,b,c) or q(d,e,f) or q(g,h,i) or q(a,d,g) or q(b,e,h) or q(c,f,i) or q(a,e,i) or q(g,e,c) else 'No')
