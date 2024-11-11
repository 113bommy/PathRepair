def ans():
    for _ in range(int(input())):
##        n = int(input())
##        l1 = list()
##        count = 2
##        for i in range(n):
##            if i == 0:
##                l1.append(count)
##            else:
##                if l1[i]%l1[i-1] == 0:
##                    count += 1
##                    l1.append(count)
##
##        for i in l1:
##            print(i,end = " ")
        n = int(input())
        for i in range(2,n+2):
            print(i, end = " ")
        print()
if __name__ == '__main__':
    ans()
