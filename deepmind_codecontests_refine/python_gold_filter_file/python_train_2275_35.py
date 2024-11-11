n = int(input())
l = list(map(int,input().split()))
m = [i%2 for i in l]
print("YNEOS"[m.count(1)%2==1::2])