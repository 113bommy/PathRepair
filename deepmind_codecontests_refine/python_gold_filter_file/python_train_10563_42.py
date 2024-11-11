n, m = [int(i) for i in input().split()]
mp = {}
for i in range (m):
    a, b = input().split()
    mp[a] = b
text = input().split()
answer = ''
for i in text:
    if len(i) <= len(mp[i]):
        answer += i + " "
    else:
        answer += mp[i] + " "
print (answer.rstrip())
