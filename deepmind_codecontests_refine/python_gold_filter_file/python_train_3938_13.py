vs = [int(i) for i in input().strip()]
n = (len(vs) - 2)//2
def main(vs):
    if vs[0] != 1:
        print(-1)
        return -1
    if vs[-1] != 0:
        print(-1)
        return -1
    if vs[-2] != 1:
        print(-1)
        return -1
    for i in range(n):
        if vs[i+1] != vs[-2-i-1]:
            print(-1)
            return

    temp = 1
    for i in range(n+1 if len(vs) % 2 == 0 else n+2):
        print(1, temp+1)
        temp += 1
    temptemp = temp
    temp = 1
    for i in range(n):
        x = 1+n-i
        if vs[n-i] == 1:
            print(temptemp, temptemp+1)
            temp = temptemp
            temptemp += 1
        else:
            print(temp, temptemp+1) 
            temptemp += 1

main(vs)
