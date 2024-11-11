S,T=input().split()
A,B=map(int,input().split())
U=input()
Dic={S:A,T:B}
Dic[U]-=1
print(Dic[S],Dic[T])