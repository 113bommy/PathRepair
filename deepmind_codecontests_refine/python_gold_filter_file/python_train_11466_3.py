n = int(input())
arr = [0]*n
for i in range(0,n):
    str1 = input()
    s = 0
    for j in range(0,len(str1)):
        if (str1[j] == ')'):
            s-=1
        else:
            s+=1
        if s<0:
            s = 0
            arr[i]-=1
    if s>0 and arr[i] == 0:
        arr[i]+=s
    elif s>0 and arr[i] < 0:
        arr[i] = -1000000
arr.sort()
l = 0
r = n-1
summ = 0
ss=set(arr)
for e in ss:
    if e>0:
        summ+=min(arr.count(e),arr.count(-1*e))
summ+=arr.count(0)//2
print(summ)
