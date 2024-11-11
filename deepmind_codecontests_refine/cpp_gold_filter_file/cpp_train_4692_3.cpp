#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
  int n;
  double x[100],y[100],sum1=0,sum2=0,sum3=0,max;

  cin>>n;
  for(int i=0;i<n;i++)cin>>x[i];
  for(int i=0;i<n;i++)cin>>y[i];
  max=fabs(x[0]-y[0]);
  for(int i=0;i<n;i++){
    sum1+=fabs(x[i]-y[i]);
    sum2+=fabs((x[i]-y[i])*(x[i]-y[i]));
    sum3+=fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
    if(max<fabs(x[i]-y[i]))max=fabs(x[i]-y[i]);
  }
  printf("%.8f\n",sum1);
  printf("%.8f\n",sqrt(sum2));
  printf("%.8f\n",pow(sum3,1.0/3.0));
  printf("%.8f\n",max);
  return 0;
}