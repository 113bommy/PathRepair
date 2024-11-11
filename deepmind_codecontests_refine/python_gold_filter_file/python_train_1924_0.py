def ofsum(num):
    num2 = 0
    for i in range(num+1):
        num2+=i
    return num2
def strspace(k):
    spaces = 11 - len(str(k)) + len(str(int(k)))
    return str(k)+'0' * spaces
def inversion(array):
    num = 0
    z = len(array)
    for i in range(z):
        for j in range(i+1,z):
            if array[i] > array[j]:
                num += 1
    return num
def reversede(array):
    z = len(array)
    for i in range(len(array)//2):
        temp = array [i]
        array[i] = array[z-i-1]
        array[z-i-1] = temp
    return array
n, k = map(int,input().split())
pn = list(map(int,input().split()))
const = 10000 / float(ofsum(n)**k)
answer = 0
if k ==1:
    for i in range(n):
        for j in range(i,n):
            pn2 = pn[:i]+reversede(pn[i:j+1])+pn[j+1:]
            answer += inversion(pn2) * const
elif k ==2:
    for i in range(n):
        for j in range(i,n):
            pn2 = pn[:i]+reversede(pn[i:j+1])+pn[j+1:]
            for i1 in range(n):
                for j1 in range(i1,n):
                    pn3 = pn2[:i1]+reversede(pn2[i1:j1+1])+pn2[j1+1:]
                    answer += inversion(pn3) * const
elif k == 3:
    for i in range(n):
        for j in range(i,n):
            pn2 = pn[:i]+reversede(pn[i:j+1])+pn[j+1:]
            for i1 in range(n):
                for j1 in range(i1,n):
                    pn3 = pn2[:i1]+reversede(pn2[i1:j1+1])+pn2[j1+1:]
                    for i2 in range(n):
                        for j2 in range(i2,n):
                            pn4 = pn3[:i2]+reversede(pn3[i2:j2+1])+pn3[j2+1:]
                            answer += inversion(pn4) * const
elif k == 4:
    for i in range(n):
        for j in range(i,n):
            pn2 = pn[:i]+reversede(pn[i:j+1])+pn[j+1:]
            for i1 in range(n):
                for j1 in range(i1,n):
                    pn3 = pn2[:i1]+reversede(pn2[i1:j1+1])+pn2[j1+1:]
                    for i2 in range(n):
                        for j2 in range(i2,n):
                            pn4 = pn3[:i2]+reversede(pn3[i2:j2+1])+pn3[j2+1:]
                            for i3 in range(n):
                                for j3 in range(i3,n):
                                    pn5 = pn4[:i3]+reversede(pn4[i3:j3+1])+pn4[j3+1:]
                                    answer += inversion(pn5) * const
print(answer/10000)
