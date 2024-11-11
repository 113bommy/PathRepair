import math
list=[]
xc=0
oc=0
for i in range(0,3):
 reg=input()
 for k in range(0,3):
  if reg[k]=="X":
   xc+=1
  elif reg[k]=="0":
   oc+=1
 list.append(reg)   
s1=list[0][0]+list[0][1]+list[0][2]
s2=list[0][2]+list[1][2]+list[2][2]
s3=list[0][0]+list[1][0]+list[2][0]
s4=list[2][0]+list[2][1]+list[2][2]
s5=list[0][1]+list[1][1]+list[2][1]
s6=list[1][0]+list[1][1]+list[1][2]
s7=list[0][0]+list[1][1]+list[2][2]
s8=list[2][0]+list[1][1]+list[0][2]
if(xc-oc>1 or(xc==oc and(s1=="XXX" or s2=="XXX" or s3=="XXX" or s4=="XXX" or s5=="XXX" or s6=="XXX" or  s7=="XXX" or s8=="XXX")and
                   ( s1=="000" or s2=="000" or s3=="000" or s4=="000" or s5=="000" or s6=="000" or s7=="000" or s8=="000")) or oc-xc>=1
   or (xc>oc and ( s1=="000" or s2=="000" or s3=="000" or s4=="000" or s5=="000" or s6=="000" or s7=="000" or s8=="000") and(s1!="XXX" and s2!="XXX" and s3!="XXX" and s4!="XXX" and s5!="XXX" and s6!="XXX" and s7!="XXX" and s8!="XXX") )
   or (xc==oc and (s1=="XXX" or s2=="XXX" or s3=="XXX" or s4=="XXX" or s5=="XXX" or s6=="XXX" or  s7=="XXX" or s8=="XXX"))): 
 print("illegal")
elif(xc==0 and oc==0):
 print("first")
else:
 if(xc-oc==1 and xc+oc!=9 and (s1!="XXX" and s2!="XXX" and s3!="XXX" and s4!="XXX" and s5!="XXX" and s6!="XXX" and s7!="XXX" and s8!="XXX" )
    and (s1!="000" and s2!="000" and s3!="000" and s4!="000" and s5!="000" and s6!="000" and s7!="000" and s8!="000") ):
  print("second")
 elif(xc==oc and xc+oc!=9 and (s1!="XXX" and s2!="XXX" and s3!="XXX" and s4!="XXX" and s5!="XXX" and s6!="XXX" and s7!="XXX" and s8!="XXX") 
    and (s1!="000" and s2!="000" and s3!="000" and s4!="000" and s5!="000" and s6!="000" and s7!="000" and s8!="000") ):
  print("first")
 elif(abs(xc-oc)==1 and s1!="XXX" and s2!="XXX" and s3!="XXX" and s4!="XXX" and s5!="XXX" and s6!="XXX" and s7!="XXX" and s8!="XXX" and s1!="000" and s2!="000" and s3!="000" and s4!="000" and s5!="000" and s6!="000" and s7!="000" and s8!="000" ):
  print("draw")
 elif( (s1!="XXX" and s2!="XXX" and s3!="XXX" and s4!="XXX" and s5!="XXX" and s6!="XXX" and s7!="XXX" and s8!="XXX") 
   and(s1=="000" or s2=="000" or s3=="000" or s4=="000" or s5=="000" or s6=="000" or s7=="000" or s8=="000")   ):
  print("the second player won")
 elif((s1=="XXX" or s2=="XXX" or s3=="XXX" or s4=="XXX" or s5=="XXX" or s6=="XXX" or  s7=="XXX" or s8=="XXX" )
    and(s1!="000" and s2!="000" and s3!="000" and s4!="000" and s5!="000" and s6!="000" and s7!="000" and s8!="000")  and xc!=oc ):
  print("the first player won")