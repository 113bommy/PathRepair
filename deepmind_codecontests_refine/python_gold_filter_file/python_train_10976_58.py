import re
n, k = [int(x) for x in input().split()]
arr = ''.join(input().split())
arr = re.sub('5', '', arr)
arr = re.sub('[6-9]', '', str(int('1' + arr) + int(str(k)*len(arr)))[1:])
print(len(arr)//3)