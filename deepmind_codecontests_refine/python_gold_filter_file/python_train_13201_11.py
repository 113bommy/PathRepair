N = int(input())
A,B = map(int,input().split())
*P, = map(int,input().split())

a = len([p for p in P if p<=A])
a = min(a,
        len([p for p in P if A<p<=B]))
a = min(a,
        len([p for p in P if B<p]))
print(a)
