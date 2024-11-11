def main():
      s1=input().split(':')
      s2=input().split(':')
      h1,h2=int(s1[0]),int(s2[0])
      m1,m2=int(s1[1]),int(s2[1])
      z=0
      if (h1+h2)%2!=0:
            z=1
      h=(h1+h2)//2
      m=(m1+m2)//2
      if z==1:
            m+=30
      if m>=60:
            m=m%60
            h+=1
      if h>=24:
            h=h%24
      if m<10:
            m='0'+str(m)
      if h<10:
            h='0'+str(h)
      print(h,m,sep=":")
main()