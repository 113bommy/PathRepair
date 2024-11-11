for s in[*open(0)][2::2]:
 a=s.split();r=[];i=0
 for x in sorted(a,key=int):j=a.index(x,i);a[i:j+1]=a[j:j+1]+a[i:j];r+=([],[i+1,j+1,j-i])[j>i];i+=1
 print(len(r)//3,*r)