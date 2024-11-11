n, k = input().split(' ')
n = int(n)
k = int(k)

j = []
for i in range(0, n):
    j.append(int(input()))

q = []
for i in range(0, k):
    q.append(0)
for i in range(0, n):
    q[j[i]-1] += 1

ans = 0
l = 0
loopEnd = 0
if (1 == n%2):
    loopEnd = int(n/2)+1
else:
    loopEnd = int(n/2)
for i in range(0, loopEnd):
    q.sort()
    q.reverse()
    if (q[l] > 2):
        # if (1 == q[l]%2):
        #     ans += 1
        ans += 2
        q[0] = q[0]-2
        # if (q[l] < 1):
        #     q[l] = 0
    else:
        ans += q[0]
        q[0] = 0
        # l += 1
    # print (ans, q)
    # print (loopEnd)

print (int(ans))