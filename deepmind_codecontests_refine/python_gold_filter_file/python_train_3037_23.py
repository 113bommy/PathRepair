n = int(input())
a = [int(i) for i in input().split()]
pre = [0]
for i in a:
    pre.append(i+pre[-1])
q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print((pre[r] - pre[l-1]) // 10)