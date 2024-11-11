t = int(input())
for i in range(t):
    n, s, k = map(int, input().split())
    l = list(map(int, input().split()))
    foo = 0
    for i in range(n):
        t1 = s + foo
        t2 = s - foo
        if (t1 <= n and t1 not in l) or (t2 > 0 and t2 not in l):
            print(foo)
            break
        foo+=1
        
