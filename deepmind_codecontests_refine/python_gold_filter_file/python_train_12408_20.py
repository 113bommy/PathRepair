
def is_different(n):

    dic = {}

    for i in str(n):

        if(i not in dic):
            dic[i] = 1

        else:
            return -1

    return n


s, e = map(int, input().split())

result = -1


for i in range(s, e+1):

    r = is_different(i)

    if(r != -1):
        result = r
        break


print(result)
