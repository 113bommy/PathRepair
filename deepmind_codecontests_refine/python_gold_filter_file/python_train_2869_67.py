n=int(input())
dictionary=[]
words=[]
for i in range(n):
    dictionary.append(input())
for word in (dictionary):
    if len(word)<=10:
        print (word)
    else:
        long=int(len(word))-2
        print(word[0]+str(long)+word[-1])