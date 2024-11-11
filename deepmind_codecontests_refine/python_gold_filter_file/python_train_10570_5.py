def arr_inp():
    return [int(x) for x in input().split()]
n=int(input())
a=arr_inp()
s1=max(a)
a.remove(s1)
s2=sum(a)
if(s1==s2):
    print(1)
else:
    print(max(s1,s2)-min(s1,s2)+1)
