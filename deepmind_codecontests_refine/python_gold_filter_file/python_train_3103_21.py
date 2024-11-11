n=int(input())
w=list(map(int, input().split()))
sn=sum(w)
abs_list=[abs(2*sum(w[:i+1])-sn) for i in range(n)]
print(min(abs_list))