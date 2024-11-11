from math import ceil
def func(n,x,y,d):
    arr=[]
    if (x-y)%d==0:
        arr.append(abs(x-y)//d)
    if y%d==1:
        arr.append(ceil(abs(x-1)/d)+(y-1)//d)
    if y%d==n%d:
        arr.append(ceil(abs(n-x)/d)+(n-y)//d)
    if arr==[]:
        print(-1)
    else:
        print(min(arr))

def main():
    count=int(input())
    for x in range(count):
        arr=input().split()
        func(int(arr[0]), int(arr[1]),int(arr[2]),int(arr[3]))
    
main()
