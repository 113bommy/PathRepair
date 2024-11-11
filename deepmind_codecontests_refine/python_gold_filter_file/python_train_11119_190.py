a=[int(input()) for _ in range(5)]
k=int(input())
print('Yay!' if max(a)-min(a)<=k else ':(')
