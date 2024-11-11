n = int(input())
arr = list(map(int, input().split()))

dic = {}
for i in range(n):
    while arr[i] in dic:
        del dic[arr[i]]
        arr[i] *= 2
    dic[arr[i]] = i

print(len(dic))
print(*dic)