for i in range(int(input())):
        n=input()
        ab=0
        ba=0
        for j in range(len(n)-1):
                s=n[j]+n[j+1]
                if s=='ab':
                    ab+=1
                elif s=='ba':
                    ba+=1
     
        if ab==ba:
            print(n)
        elif ab<ba:
            print('a'+n[1:])    
        elif ba<ab:
            print(n[:len(n)-1]+"a")


