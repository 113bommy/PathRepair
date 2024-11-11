n=int(input())
arr=input()
arr=sorted(list(map(int,arr.split())))
a=arr[::2]
b=arr[1::2]
if(len(set(a))+len(set(b))!=n):
   print("NO")
else:
    print("YES")
    print(len(a))
    print(*a)
    print(len(b))
    print(*b[::-1])

   