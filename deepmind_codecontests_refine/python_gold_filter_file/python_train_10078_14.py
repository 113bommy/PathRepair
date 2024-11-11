n = int(input())
*a, = map(int, input().split())
*a_abs, = map(abs, a)
if len([i for i in a if i<0])%2==0:
    print(sum(a_abs))
else:
    print(sum(a_abs)-2*min(a_abs))