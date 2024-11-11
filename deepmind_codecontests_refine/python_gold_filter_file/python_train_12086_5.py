#joto gula common item ache, sorting er por jodi totobar left shift kori tahole maximum number paoa jay.
#ar joto bar shift korbo bam theke toto gula number dane chole jabe ar answer totoi komte thakbe.
#orthat jodi maximux x ta common item thake tahole x bar shift hobe . tai answer hobe n-x



n=int(input())
li=list(map(int,input().split(" ")))
li.sort()
ma=1
count=1
i=0
while i<len(li)-1:
    if li[i]==li[i+1]:
        count+=1
        ma=max(ma,count)
    else:

        count=1
    i+=1

print(n-ma)