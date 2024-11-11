N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

count = [0] * (N+1)
for a, b in zip(A, B):
    count[a] += 1
    count[b] += 1

for i in range(N+1):
    if count[i] > N:
        print('No')
        quit()

diff = 0
checked = set()
ida = 0
for i, b in enumerate(B):
    if b in checked:
        continue
    checked.add(b)
    while ida < N and A[ida] <= b:
        ida += 1
    diff = max(diff, ida - i)


print('Yes')
print(*(B[-diff:]+B[:-diff]))