t=int(input())
x=0
c=0
while(t>0):
    t=t-1
    l=str(input())
    ab=l.count('ab')
    ba=l.count('ba')
    if ab==ba:
        print(l)
    elif ab>ba:
        print(l[:-1]+'a')
    elif ab<ba:
        print(l[:-1] + 'b')
