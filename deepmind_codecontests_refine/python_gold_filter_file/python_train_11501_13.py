def generate1(long,sum1):
    if (9*long>=sum1 and sum1>=1) or (long==1 and sum1==0):
        if long==1 and sum1>=1 and sum1<=9:
            return sum1
        elif sum1>9:
            sum1-=9
            long-=1
            return generate1(long,sum1)+9*pow(10,long)
        elif sum1<=9:
            long-=1
            return sum1*pow(10,long)
    else:
        return -1


def generate2(long,sum1):
    if (9*long>=sum1 and sum1>=1) or (long==1 and sum1==0):
        if sum1>9:
            sum1-=9
            long-=1
            return generate2(long,sum1)*10+9
        if sum1<=9:
            return sum1-1+1*pow(10,long-1)
    else:
        return -1

    
x=[int(i) for i in input().split()]
print('%d %d'% (generate2(x[0],x[1]),generate1(x[0],x[1])))