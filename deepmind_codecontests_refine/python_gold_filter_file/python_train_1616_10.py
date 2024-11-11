

def is_beautiful(s):
    if '2' in s or '3' in s or '4' in s or '5' in s or '6' in s or '7' in s or '8' in s or '9' in s:
        return 0
    elif s.find('1') == s.rfind('1'):
        return 1
    else:
        return 0


n = int(input())
zeroFlag = 0
nonBeautiful = 0
nBFlag = 0
zCount = 0
nums = input().split()
a = []
for i in range(n):
    a.append(nums[i])
    if not nBFlag and not is_beautiful(str(a[i])):
        nonBeautiful = a[i]
        nBFlag = 1
    else:
        zCount += len(a[i]) - 1
    if str(a[i]) == '0':
        zeroFlag = 1
        break
    i += 1
if zeroFlag:
    print(0)
elif nBFlag:
    print(str(nonBeautiful) + '0' * zCount)
else:
    print(str(1) + '0'*zCount)
