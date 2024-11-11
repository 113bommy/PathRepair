def BtoE(a):
    s=''
    while a>=8:
        s=str(a%8)+s
        a=a//8
    if a!=0:
        s=str(a)+s
    return s
def cal(s):
    sum1=0
    for i in s:
        if i=='1':
            sum1+=1
    return sum1
print(cal(BtoE(int(input()))))