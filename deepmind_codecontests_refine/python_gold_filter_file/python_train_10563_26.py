a,b=map(int,input().strip().split())
lang1=[]
lang2=[]
for _ in range(b):
    l=list(map(str,input().strip().split()))
    lang1.append(l[0])
    lang2.append(l[1])
lecture=list(map(str,input().split()))

for i in lecture:

    indexInLang1=lang1.index(i)
    if len(lang1[indexInLang1])>len(lang2[indexInLang1]):
        print(lang2[indexInLang1],end=" ")
    else:
        print(lang1[indexInLang1],end=" ")