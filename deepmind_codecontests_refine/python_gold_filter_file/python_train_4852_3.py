n,angle=[int(element) for element in input().split(" ")]

best_vertice=3
best_angle=-1
for end in range(3,n+1):
    actual_angle=360/n*(end-2)/2
    difference=abs(angle-actual_angle)
    if best_angle==-1 or difference<best_angle:
        best_angle=difference
        best_vertice=end

print("2 1 "+str(best_vertice))