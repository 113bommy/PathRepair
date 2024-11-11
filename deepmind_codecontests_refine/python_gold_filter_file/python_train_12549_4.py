def Count(l):
    if len(l) == 1:
        if l[0] == 0:
            return False
        else:
            return True
    zeros = 0
    for i in l:
        if i == 0:
            if zeros == 0:
                zeros += 1
            else:
                return False
    if zeros == 1:
        return True
    return False


n = int(input())
li = list(map(int, input().split()))
if Count(li):
    print("YES")
else:
    print("NO")
