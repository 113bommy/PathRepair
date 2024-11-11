S,T=input().split()
A,B=map(int,input().split())
U=input()
dic={S:A,T:B}
dic[U]-=1
print(dic[S],dic[T])