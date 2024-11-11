n1,n2,n3=map(int,input().split())
a1=list(map(int,input().split()))
a2=list(map(int,input().split()))
a3=list(map(int,input().split()))
s1=sum(a1)
s2=sum(a2)
s3=sum(a3)
m1=min(a1)
m2=min(a2)
m3=min(a3)
val=min(m1+m2,m2+m3,m3+m1,min(s1,s2,s3))
print(s1+s2+s3-2*val)

#Suppose elements in 1st box are: a1,a2,..an1, 2nd box: b1,b2,...,bn2, 3rd box: c1,c2,...,cn3
#Any operation on removing an element reduces the total sum of elements in all boxes by that element
#In the proccess of bringing all elements from one box to another(say 1sst box to 2nd), we can "preserve" the sum of atmost (n1-1)+(n2-1) elements
#To maximise the sum we preserved, we "remove" the minimum element of box1 and minimum element of box2
#if m1 is min of box1 and m2 is min of box2, we can preserve the total sum of box 1 + box 1 - m1 - m2
# this can be done as the operations: m1-a1,m1-a1-a2,...,m1-a1-a2-...an1(m1 not equal ai in this difference) in box 1, b1-m2,b1+b2-m2,....,b1+b2+...+bn-m2
#followed by b1+b2+...+bn-m2-(m1-a1-...an1) (operations between the last element left in box1 and box2)
# to preserve sum of elements of box3 also in above sum, extend the operation of box2 to m2-b1-...-bn2-c1-c2-...cn3
#so overall, this gives sum(box1+box2+box3 other than m1,m2)-m1-m2
#To maximum above value further, take the two minimum's as the two minimums out of the three minimums of all the three boxes
#But in case the numbers in the boxes are really far apart, example(1,2,3) in box 1 (9999,9998,9997) in box 2 and box3
#conserving just the two minimums out of the three boxes isn't optimal.
# in this case, using similar operations, we remove the minimum sum of all the three boxes
# this can be done as(say box 1 has minimum sum): b1->b1-a2-a3-...an1, a1-> a1-b2-b3...bn2-c1-c2...-cn3, b1-> b1-a1
