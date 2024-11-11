n = int(input())
d1 = n//10
d2 = n%10
def c(k):
    if(k==0):
        return 2
    if(k==1):
        return 7
    if(k==2):
        return 2
    if(k==3):
        return 3
    if(k==4):
        return 3
    if(k==5):
        return 4
    if(k==6):
        return 2
    if(k==7):
        return 5
    if(k==8):
        return 1
    if(k==9):
        return 2
print(c(d1)*c(d2))