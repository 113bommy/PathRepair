#AIsing2020 d

def f(n):
        cnt = 0
        while n:
            cnt+= 1
            n = n%bin(n).count('1')
        return cnt

def main():
    N = int(input())
    X = input()
    X10 = int(X,2)
    X10_num1 = X.count('1')
    X10_pulse = X10%(X10_num1+1)
    X10_ninus = X10%(X10_num1-1) if X10_num1 >1 else 0


    for i in range(N,0,-1):
        j = N-i
        if (X[j] == '1') and X10_num1 >1:
            mod = X10_num1-1
            amari = (X10_ninus - pow(2,i-1,mod))%(mod) 
        elif (X[j] == '1') and X10_num1 ==1:
            print(0)
            continue
        else:
            mod = X10_num1+1
            amari = (X10_pulse + pow(2,i-1,mod))%(mod)

        print(1+f(amari))


main()
