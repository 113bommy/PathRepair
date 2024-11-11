q=int(input())
for i in range(q):
    n,k=[int(i) for i in input().split(" ")]
    a=[int(i) for i in input().split(" ")]
    l=min(a)+k
    r=max(a)-k
    if l<r:
        l=-1
    print(l)