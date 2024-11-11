#n = int(input())
#n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
p = set(['a', 'e', 'o', 'i', 'u', '1', '3', '5', '7', '9'])
l = 0
for i in s:
    if i in p:
        l += 1
print(l)