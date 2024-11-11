n = int(input())
a = input()
d = {'0':'', '1':'', '2':'2', '3':'3', '4':'322', '5':'5', '6':'53', '7':'7', '8':'7222', '9':'7332'}
ans = ''
for i in a:
    ans += d[i]
ans = list(map(int, list(ans)))
ans.sort(reverse=True)
print(''.join(map(str, ans)))
