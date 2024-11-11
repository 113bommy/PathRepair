import sys
input = sys.stdin.readline

'''

'''

n = int(input())
a = list(map(int, input().split()))
a.sort()
pf_sum = [a[0]]
for i in range(1, n):
    pf_sum.append(pf_sum[-1] + a[i])

if pf_sum[-1] % 2:
    print("NO")
    sys.exit()
elif pf_sum[-1] > 2 * pf_sum[-2]:
    print("NO")
    sys.exit()
else:
    print("YES") 