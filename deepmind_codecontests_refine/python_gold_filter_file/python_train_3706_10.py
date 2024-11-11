
def prime(N):
    flag1 = 1
    for i in range(2,int(N)):
        if N%i == 0:
            flag1 = 0
            break
    return flag1

if __name__ == '__main__':
    len = input()
    flag = 0
    inputlist = []
    inputlist = len.split(' ')
    n = int(inputlist[0])
    m = int(inputlist[1])
    for i in range(n+1,51):
        if prime(i) == 1:
            flag = 1
            break
    #   else:
    #       flag = "NO"
    #if prime(len) == 1:
    #    print("YES")
    #else:
    if i == m and flag == 1:
        print("YES")
    else:
        print("NO")
    #print(flag)

