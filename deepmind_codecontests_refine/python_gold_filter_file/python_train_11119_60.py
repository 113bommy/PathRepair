a=[int(input()) for x in range(5)]
k=int(input())
print('Yay!' if max(a)-min(a)<=k else ':(')