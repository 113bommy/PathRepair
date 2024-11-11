n=list(range(1,int(input())+1))
print(sum([i for i in n if i%3!=0and i%5!=0]))