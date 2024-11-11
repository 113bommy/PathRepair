_, k = map(int, input().split())
print(len(list(filter(lambda x:x<=5-k,map(int,input().split()))))//3)